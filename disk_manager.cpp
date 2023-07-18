#include "disk_manager.h"

namespace riverrain{


DiskManager::DiskManager(const char * pname) : path_name_{pname} {
            fd_ = open(path_name_, O_RDWR | O_DIRECT | O_CREAT, S_IRWXU);
            if(fd_ < 0){
                throw( "data file error");
            }
            
}

void DiskManager::ShutDown(){
            int c = close(fd_);
            if(c < 0){
                throw("close data file error");
            }
}

void DiskManager::ReadBlockFromDisk(block_id_t block_id, char * block_data){
            size_t offset = static_cast<size_t>(block_id) * BLOCK_SIZE;
            
}
}
