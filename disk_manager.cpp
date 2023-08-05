#include "disk_manager.h"

namespace riverrain{


DiskManager::DiskManager(const char * pname) : path_name_(pname), disk_pool_size(DISK_SIZE/RAW_BLOCK_SIZE){
            fd_ = open(path_name_, O_RDWR | O_DIRECT | O_CREAT, S_IRWXU);

            int err = truncate(path_name_,DISK_SIZE);
            
            
            if(fd_ < 0 || err < 0){
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
            size_t offset = static_cast<size_t>(block_id) * RAW_BLOCK_SIZE;
            if(offset > GetFileSize(this->path_name_)){ //offset > GetFileSize(this->path_name_)
                 throw std::runtime_error("file offset out of range at DiskManager ReadBlockFromDisk");
            } else{
                     auto f_ptr = lseek(this->fd_, offset, SEEK_SET);
                     if(f_ptr == -1){
                        throw std::runtime_error("data file seek fail at ReadBlockFromDisk");
                     }
                     int len = read(this->fd_,block_data,RAW_BLOCK_SIZE);
                     if(len == - 1){
                        throw std::runtime_error("data file read fail at ReadBlockFromDisk");
                     }
            }
            return;            
}
 void DiskManager::WriteBlockToDisk(block_id_t block_id, const char *block_data){
           size_t offset = static_cast<size_t>(block_id* RAW_BLOCK_SIZE);
            if(offset > GetFileSize(this->path_name_)){ // offset > GetFileSize(this->path_name_)
                 throw std::runtime_error("file offset out of range at DiskManager WriteBlockToDisk");
            } else{
                     auto f_ptr = lseek(this->fd_, offset, SEEK_SET);
                     if(f_ptr == -1){
                        throw std::runtime_error("data file seek fail at WriteBlockToDisk");
                     }
                     int len = write(this->fd_, block_data,RAW_BLOCK_SIZE);
                     if(len == - 1){
                        std::cout << errno << std::endl;
                        throw std::runtime_error("data file write fail at WriteBlockToDisk");
                     }
            }
            return;   
 }



auto DiskManager::GetFileSize(const std::string &file_name) -> int {
  struct stat stat_buf;
  int rc = stat(file_name.c_str(), &stat_buf);
  return rc == 0 ? static_cast<int>(stat_buf.st_size) : -1;
}


}
