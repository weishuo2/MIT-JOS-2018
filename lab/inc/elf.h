#ifndef JOS_INC_ELF_H
#define JOS_INC_ELF_H

#define ELF_MAGIC 0x464C457FU	/* "\x7FELF" in little endian */

struct Elf {
	uint32_t e_magic;	// must equal ELF_MAGIC
	uint8_t e_elf[12];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint32_t e_entry;//程序入口地址
	uint32_t e_phoff;//program header table在文件中的偏移地址
	//Program header描述的是一个段在文件中的位置、大小以及它被放进内存后所在的位置和大小。
	uint32_t e_shoff;//section header table在文件中的偏移地址
	uint32_t e_flags;
	uint16_t e_ehsize;//ELF header的大小
	uint16_t e_phentsize;//program header table每一个条目大小
	uint16_t e_phnum;//条目数目
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
};

struct Proghdr {
	uint32_t p_type;//段的类型
	uint32_t p_offset;//段的偏移地址
	uint32_t p_va;//段第一个字节的虚拟地址
	uint32_t p_pa;
	uint32_t p_filesz;//段在文件中的长度
	uint32_t p_memsz;//段在内存中的长度
	uint32_t p_flags;
	uint32_t p_align;
};

struct Secthdr {
	uint32_t sh_name;
	uint32_t sh_type;
	uint32_t sh_flags;
	uint32_t sh_addr;
	uint32_t sh_offset;
	uint32_t sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uint32_t sh_addralign;
	uint32_t sh_entsize;
};

// Values for Proghdr::p_type
#define ELF_PROG_LOAD		1

// Flag bits for Proghdr::p_flags
#define ELF_PROG_FLAG_EXEC	1
#define ELF_PROG_FLAG_WRITE	2
#define ELF_PROG_FLAG_READ	4

// Values for Secthdr::sh_type
#define ELF_SHT_NULL		0
#define ELF_SHT_PROGBITS	1
#define ELF_SHT_SYMTAB		2
#define ELF_SHT_STRTAB		3

// Values for Secthdr::sh_name
#define ELF_SHN_UNDEF		0

#endif /* !JOS_INC_ELF_H */
