

#include "disk_manager.h" 
#include "buffer_pool_manager.h"
#include <iostream>
    // disk_manager test
    // int main(){
        
    //     riverrain::DiskManager dm("test.txt");
    //     char * wbuffer = new char[4096 * 4];
    //     char * rbuffer = new char[4096 * 4];

    //     auto ret = posix_memalign((void **)&wbuffer, 512, riverrain::BLOCK_SIZE);
    //     auto ret1 = posix_memalign((void **)&rbuffer, 512, riverrain::BLOCK_SIZE);

        

    //     memcpy(wbuffer,"yuan",sizeof("yuan"));
        

    //     dm.WriteBlockToDisk(1,wbuffer);
    //     dm.ReadBlockFromDisk(1,rbuffer);
    //     std::cout << rbuffer << std::endl;
    //     dm.ShutDown();
    //     return 1;

    // }

using namespace riverrain;

int main(){
        DiskManager dm("test.txt");
        
        BufferPoolManager bf(3 * BLOCK_SIZE, &dm);
        std::cout << bf.blocks_[1].a << std::endl;
        return 1;
        // void * ptr = aligned_alloc(1024, 1024 * sizeof(int));
}