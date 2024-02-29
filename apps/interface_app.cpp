//
// Created by zolkin on 2/28/24.
//

//#include <boost/interprocess/shared_memory_object.hpp>
//#include <boost/interprocess/mapped_region.hpp>
//#include <boost/interprocess/sync/scoped_lock.hpp>
//#include <boost/interprocess/sync/interprocess_mutex.hpp>
//#include <iostream>
//#include <cstdio>

#include "client_interface.h"

int main ()
{
    stream_client::ClientInterface interface;
    interface.ReadOptiTrackData();
}