#include "object_manager.h"



namespace riverrain{

    auto ObjectManager::FetchObject(const std::string & object_name) -> std::pair<const char *,size_t>{
                        auto ite = this->object_map_.find(object_name);
                        if(ite == this->object_map_.end()){
                                    //TODO
                        }
                        else{
                                       ObjectPos & op = (*ite).second;
                                       RawBlock * rawb = this->memory_pool_->FetchBlock(op.b_id);
                                       ObjectBlock * objb = reinterpret_cast<ObjectBlock *>(rawb->GetData());
                                       return objb->ContentAt(op.idx);
                        }

    }
}