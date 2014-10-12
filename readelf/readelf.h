/*
 * =====================================================================================
 *
 *       Filename:  elf.h
 *
 *    Description:  ELF格式的头文件
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

struct 
elf_section {
	unsigned int sh_name;
	unsigned int sh_type;
	unsigned int sh_flags;
	unsigned int sh_addr;
	unsigned int sh_offset;
	unsigned int sh_size;
	unsigned int sh_link;
	unsigned int sh_info;
	unsigned int sh_addralign;
	unsigned int sh_entsize;
};
#endif /*ELF_H*/
