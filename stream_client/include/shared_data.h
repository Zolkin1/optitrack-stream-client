//
// Created by zolkin on 2/28/24.
//

#ifndef OPTITRACK_STREAM_CLIENT_SHARED_DATA_H
#define OPTITRACK_STREAM_CLIENT_SHARED_DATA_H

namespace stream_client {
    struct OptiTrackRBData {
        //Mutex to protect access to the queue
        boost::interprocess::interprocess_mutex mutex;

        static constexpr int NUM_RIGID_BODIES = 1;

        std::array<double, NUM_RIGID_BODIES> x;
        std::array<double, NUM_RIGID_BODIES> y;
        std::array<double, NUM_RIGID_BODIES> z;

        std::array<double, NUM_RIGID_BODIES> qx;
        std::array<double, NUM_RIGID_BODIES> qy;
        std::array<double, NUM_RIGID_BODIES> qz;
        std::array<double, NUM_RIGID_BODIES> qw;
    };
} // stream_client

#endif //OPTITRACK_STREAM_CLIENT_SHARED_DATA_H
