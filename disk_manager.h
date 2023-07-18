
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
        

};
}



#endif

