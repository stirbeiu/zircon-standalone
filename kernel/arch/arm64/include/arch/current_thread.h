// Copyright 2016 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#pragma once

__BEGIN_CDECLS

/* use the cpu local thread context pointer to store current_thread */
static inline struct thread* get_current_thread(void) {
    char* tp = (char*)ARM64_READ_SYSREG(tpidr_el1);
    tp -= offsetof(struct thread, arch.thread_pointer_location);
    return (struct thread*)tp;
}

static inline void set_current_thread(struct thread* t) {
    ARM64_WRITE_SYSREG(tpidr_el1, (uint64_t)&t->arch.thread_pointer_location);
}

__END_CDECLS
