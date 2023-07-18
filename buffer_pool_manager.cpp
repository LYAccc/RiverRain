#include "buffer_pool_manager.h" 

namespace riverrain{
     BufferPoolManager::BufferPoolManager(size_t pool_size_bytes, DiskManager * disk_manager): pool_size(pool_size_bytes/BLOCK_SIZE) {
                            
    }
}

