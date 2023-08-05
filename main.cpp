

#include "disk_manager.h" 
#include "memory_manager.h"
#include "object_block.h"
#include <iostream>
#include <unordered_set>
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
        
        MemoryManager bf(3 * RAW_BLOCK_SIZE, &dm);
        
        
        void * raw = malloc(1000);
        ObjectBlock * r = reinterpret_cast<ObjectBlock *> (raw);
        
        std::string s = "abc";
        

        std::cout << s.data()[0];

        ;
        

        // void * ptr = aligned_alloc(1024, 1024 * sizeof(int));
	// for test
}
