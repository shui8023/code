/*
 * =====================================================================================
 *
 *       Filename:  elf.h
 *
 *    Description:  ELF格式的头文件(只是针对32位的elf文件)
 *
 *        Version:  1.0
 *        Created:  2014年10月10日 11时04分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#ifndef ELF_H
#define ELF_H

//elf的头部
struct 
elf {
	unsigned  char 		e_ident[16];
	unsigned  short  	e_type;
	unsigned  short 	e_machine;
	unsigned  int 		e_version;
	unsigned  int	 	e_entry;
	unsigned  int		e_phoff;
	unsigned  int		e_shoff;
	unsigned  int	 	e_flags;
	unsigned  short 	e_ehsize;
	unsigned  short 	e_phentsize;
	unsigned  short 	e_phnum;
	unsigned  short 	e_shentsize;
	unsigned  short 	e_shnum;
	unsigned  short 	e_shstrndx;
};

//elf文件的节区表
struct 
elf_section {
	unsigned int 	 sh_name;
	unsigned int 	 sh_type;
	unsigned int 	 sh_flags;
	unsigned int 	 sh_addr;
	unsigned int 	 sh_offset;
	unsigned int 	 sh_size;
	unsigned int 	 sh_link;
	unsigned int 	 sh_info;
	unsigned int 	 sh_addralign;
	unsigned int 	 sh_entsize;
};

//elf文件的程序头部，与elf头部不一样
struct 
elf_header {
	unsigned int 	p_type;
	unsigned int 	p_offset;
	unsigned int 	p_vaddr;
	unsigned int 	p_paddr;
	unsigned int 	p_filesz;
	unsigned int 	p_memze;
	unsigned int 	p_flags;
	unsigned int 	p_align;
};
#endif /*ELF_H*/
