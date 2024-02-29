//
// Created by zolkin on 2/28/24.
//

#ifndef OPTITRACK_STREAM_CLIENT_CLIENT_INTERFACE_H
#define OPTITRACK_STREAM_CLIENT_CLIENT_INTERFACE_H

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <iostream>
#include <cstdio>

#include <Eigen/Core>

#include "client.h"

namespace stream_client {
    using namespace boost::interprocess;

    class ClientInterface {
    public:
        #define MEM_NAME "optitrack-client:shared_mem2"

        ClientInterface();

        void ReadOptiTrackData(Eigen::Vector<double, 7>& q);

        ~ClientInterface();
    protected:
    private:
        shared_memory_object shared_mem_;
        std::unique_ptr<mapped_region> mem_region_;
    };
} // stream_client


#endif //OPTITRACK_STREAM_CLIENT_CLIENT_INTERFACE_H
