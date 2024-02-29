//
// Created by zolkin on 2/28/24.
//

#include "client_interface.h"
#include "shared_data.h"

namespace stream_client {
    using namespace boost::interprocess;

    ClientInterface::ClientInterface() : shared_mem_(open_only, MEM_NAME, read_only) {
        mem_region_ = std::make_unique<mapped_region>(shared_mem_, read_only);
    }

    void ClientInterface::ReadOptiTrackData(Eigen::Vector<double, 7>& q) {
        void* addr = mem_region_->get_address();

        auto* data = static_cast<OptiTrackRBData*>(addr);

        scoped_lock<interprocess_mutex> lock(data->mutex);
        for (int i = 0; i < OptiTrackRBData::NUM_RIGID_BODIES; i++) {
            std::cout << "RB " << i << ", x: " << data->x.at(i) << std::endl;
            std::cout << "RB " << i << ", y: " << data->y.at(i) << std::endl;
            std::cout << "RB " << i << ", z: " << data->z.at(i) << std::endl;
        }

        // For now only use one rigid body
        q(0) = data->x[0];
        q(1) = data->y[0];
        q(2) = data->z[0];
        q(3) = data->qx[0];
        q(4) = data->qy[0];
        q(5) = data->qz[0];
        q(6) = data->qw[0];
    }

    ClientInterface::~ClientInterface() {
        shared_memory_object::remove(MEM_NAME);
    }
} // stream_client