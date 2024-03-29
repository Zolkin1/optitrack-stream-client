//
// Created by zolkin on 2/28/24.
//

#ifndef OPTITRACK_STREAM_CLIENT_CLIENT_H
#define OPTITRACK_STREAM_CLIENT_CLIENT_H

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <iostream>
#include <cstdio>

namespace stream_client {
    class Client {
    public:
        #define MEM_NAME "optitrack-client:shared_mem2"

        Client(double data_rate);

        void Listen();

        ~Client();

    protected:
        void WriteDataToMemory();

    private:
        struct shm_remove
        {
            shm_remove() { boost::interprocess::shared_memory_object::remove(MEM_NAME); }
            ~shm_remove(){ boost::interprocess::shared_memory_object::remove(MEM_NAME); }
        } remover_;

        boost::interprocess::shared_memory_object shared_mem_;
        std::unique_ptr<boost::interprocess::mapped_region> mem_region_;

        double data_rate_;
        bool initialized_;
    };
} // stream_client


#endif //OPTITRACK_STREAM_CLIENT_CLIENT_H
