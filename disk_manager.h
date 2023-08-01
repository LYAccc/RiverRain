
#ifndef DISK_MANAGER_H
#define DISK_MANAGER_H

#include <string>
#include <fcntl.h>      
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "config.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <lru_k_replacer.h>

namespace riverrain{
class DiskManager{
    
    public:
        explicit DiskManager(const char * path_name);

        void ShutDown();

        virtual void WriteBlockToDisk(block_id_t block_id, const char *block_data);

        virtual void ReadBlockFromDisk(block_id_t block_id, char * block_data);

        

    protected:
        auto GetFileSize(const std::string &file_name) -> int;
        int fd_;
        const char * path_name_;
        const size_t disk_pool_size;
        // to support buffer function
        std::unique_ptr<LRUKReplacer> replacer_;
        std::list<frame_id_t> free_list_;
        std::unordered_map<block_id_t, frame_id_t> block_table_;


};
}



#endif

