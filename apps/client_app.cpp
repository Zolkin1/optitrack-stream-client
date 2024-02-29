//
// Created by zolkin on 2/28/24.
//

#include "client.h"

int main() {
    // TODO: works when the computer is NOT set to loopback
    stream_client::Client client(300);
    client.Listen();
}