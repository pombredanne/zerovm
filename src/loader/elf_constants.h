/*
 * Copyright 2008, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Copyright (c) 2012, LiteStack, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* @file
 *
 * Defines common constants used in ELF files, used by elf32.h, elf64.h
 * and elf.h
 *
 * (Re)Created from the ELF specification at
 * http://x86.ddj.com/ftp/manuals/tools/elf.pdf which is referenced
 * from wikipedia article
 * http://en.wikipedia.org/wki/Executable_and_Linkable_Format
 */

#ifndef ELF_CONSTANTS_H_
#define ELF_CONSTANTS_H_

#include "src/main/nacl_base.h"

EXTERN_C_BEGIN

#define EI_NIDENT       16   /* fwd, see rest of EI_* below */

#define ET_NONE         0   /* no file type */
#define ET_REL          1   /* relocatable file */
#define ET_EXEC         2   /* executable file */
#define ET_DYN          3   /* shared object file */
#define ET_CORE         4   /* core file */

/* all platforms (but x86_64) removed */
#define EM_X86_64       62  /* x86-64 */

#define EM_EXPECTED_BY_NACL EM_X86_64

#define EV_NONE         0   /* invalid version */
#define EV_CURRENT      1   /* current version */

#define EI_MAG0         0   /* file identification */
#define EI_MAG1         1   /* file identification */
#define EI_MAG2         2   /* file identification */
#define EI_MAG3         3   /* file identification */
#define EI_CLASS        4   /* file class */
#define EI_DATA         5   /* data encoding */
#define EI_VERSION      6   /* file version */

/*
 * ELFMAG and SELFMAG are names/values from linux elf.h, for code usage
 * compatibility.
 */
#define ELFMAG          "\177ELF"
#define SELFMAG         4

/* EI_CLASS values */
#define ELFCLASSNONE    0
#define ELFCLASS32      1
#define ELFCLASS64      2

/* EI_DATA values */
#define ELFDATANONE     0
#define ELFDATA2LSB     1
#define ELFDATA2MSB     2

#define PT_NULL       0           /* Unused entry */
#define PT_LOAD       1           /* Loadable segment */
#define PT_DYNAMIC    2           /* Dynamic linking tables */
#define PT_INTERP     3           /* Program interpreter path name */
#define PT_NOTE       4           /* Note section */
#define PT_SHLIB      5           /* Reserved */
#define PT_PHDR       6           /* Program header table */
#define PT_LOOS       0x60000000  /* Environment-specific low */
#define PT_HIOS       0x6fffffff  /* Environment-specific high */
#define PT_LOPROC     0x70000000  /* Processor-specific low */
#define PT_HIPROC     0x7fffffff  /* Processor-specific high */
/*
 * These are from linux elf.h, for code usage
 * compatibility.
 */
#define PT_TLS        7
#define PT_GNU_STACK  0x6474e551
#define PT_GNU_EH_FRAME 0x6474e550      /* GCC .eh_frame_hdr segment */
#define PT_GNU_RELRO    0x6474e552      /* Read-only after relocation */

#define PF_X          1
#define PF_W          2
#define PF_R          4

#define SHF_WRITE       0x1         /* Has writable data */
#define SHF_ALLOC       0x2         /* Allocated in memory image of program */
#define SHF_EXECINSTR   0x4         /* Contains executable instructions */
#define SHF_MASKOS      0x0f000000  /* Environment-specific use */
#define SHF_MASKPROC    0xf0000000  /* Processor-specific use */

EXTERN_C_END

#endif  /* ELF_CONSTANTS_H_ */
