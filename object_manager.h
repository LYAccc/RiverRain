


#include "config.h"
#include <unordered_map>
#include "memory_manager.h"
#include <memory>
#include "raw_block.h"
#include "object_block.h"
namespace riverrain{


    struct ObjectPos{
                block_id_t b_id;
                int idx;
    };

    class ObjectManager
    {
       
    public:
        ObjectManager(/* args */);
        ~ObjectManager();
        auto FetchObject(const std::string & object_name) -> std::pair<const char *, size_t>;
        auto WriteObjectToMemory(const std::string & object_name, const char * data,size_t object_length) -> bool;
        auto CheckExistence(const std::string & object_name) const -> bool;

    private:
        std::unordered_map<std::string, ObjectPos> object_map_;
        std::unique_ptr<MemoryManager> memory_pool_;

    };
    

    


}