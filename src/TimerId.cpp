//
// Created by Brandon on 12/26/24.
//

#include "TimerId.h"

TimerId::TimerId(): pimpl(nullptr), version(0) {

}

TimerId::TimerId(void* pimpl, u16 version): pimpl(pimpl), version(version) {

}