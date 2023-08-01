#include "lru_k_replacer.h"

namespace riverrain {

LRUKReplacer::LRUKReplacer(size_t num_frames, size_t k) : replacer_size_(num_frames), k_(k) {}

auto LRUKReplacer::Evict(frame_id_t *frame_id) -> bool { return false; }

void LRUKReplacer::RecordAccess(frame_id_t frame_id) {}

void LRUKReplacer::SetEvictable(frame_id_t frame_id, bool set_evictable) {}

void LRUKReplacer::Remove(frame_id_t frame_id) {}

auto LRUKReplacer::Size() -> size_t { return 0; }

} 