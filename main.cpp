

#include "disk_manager.h" 

#include <iostream>
    // disk_manager test
    int main(){
        
        riverrain::DiskManager dm("test.txt");
        char * wbuffer = new char[4096 * 4];
        char * rbuffer = new char[4096 * 4];

        auto ret = posix_memalign((void **)&wbuffer, 512, riverrain::BLOCK_SIZE);
        auto ret1 = posix_memalign((void **)&rbuffer, 512, riverrain::BLOCK_SIZE);

        

        memcpy(wbuffer,"hello",sizeof("hello"));
        

        dm.WriteBlockToDisk(0,wbuffer);
        dm.ReadBlockFromDisk(0,rbuffer);
        std::cout << rbuffer << std::endl;
        dm.ShutDown();
        return 1;

    }
