/*
 * =====================================================================================
 *
 *       Filename:  elf.c
 *
 *    Description:  支持32位下的elf文件的elf headers读取，和readelf的-h输出一样，只支持32的elf文件
 *
 *
 *        Version:  1.0
 *        Created:  2014年10月10日 11时04分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readelf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>


static const char *
get_elf_class(unsigned int elf_class)
{
	static char buff[32];

	switch (elf_class) 
	{
	case 0: return "none";
	case 1: return "ELF32";
	case 2: return "ELF64";
	default:
		snprintf(buff, sizeof(buff), "<unknown: %x>", elf_class);
		return buff;
	}

}

static const char *
get_elf_data(unsigned int elf_data) 
{
	static char buff[32];

	switch(elf_data) 
	{
	case 0: return "none";
	case 1: return "2's complement, little endian";
	case 2: return "2's complement, big endian";
	default:
		snprintf(buff, sizeof(buff), "<unknown:%x>", elf_data);
		return buff;
	}
}

static const char *
get_osabi_name(unsigned int osabi)
{
	static char buff[32];

	switch (osabi) 
	{
	case 0: return "UNIX - System V";
	case 1: return "UNIX - HP-UX";
	case 2: return "UNIX - NetBSD";
	case 3: return "UNIX - GNU";
	case 6: return "UNIX - Solaris";
	case 7: return "UNIX - AIX";
	case 8: return "UNIX - IRIX";
	case 9: return "UNIX - FreeBSD";
	case 10: return "UNIX - TRU64";
	case 11: return "Nove11 - Modesto";
	case 12: return "UNIX - OpenBSD";
	case 13: return "VMS - OpenVMS";
	case 14: return "HP - Non-Stop kernel";
	case 15: return "AROS";
	case 16: return "FenixOS";
	default:
		 return buff;
	}
}

static const char *
get_file_type (unsigned int e_type)
{
	static char buff[32];

	switch (e_type) 
	{
	case 0 : 	return "NONE (none)";
	case 1 : 	return "REL (Relocatable file)";
	case 2 :  	return "EXEC (Executable file)";
	case 3 : 	return "DYN (shared object file)";
	case 4 : 	return "CORE (Core file)";
	default:
		return buff;
	}
}

static const char *
get_machine_name (unsigned int machine)
{
	return "none";
}

//获取elf头部
static void 
get_elf_header (char *filename)
{
	int fd;
	struct elf elf;
	int i;

	if ((fd = open("a.out", O_RDONLY, 0644)) == -1) {
		printf("error\n");
	}

	read(fd, &elf, sizeof(struct elf));
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; ++i) {
		printf("%2.2x ", elf.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                %s\n", get_elf_class(elf.e_ident[4]));
	printf("  Date:                 %s\n", get_elf_data(elf.e_ident[5]));
	printf("  Version:              %d%s\n", elf.e_ident[6], "(current)");
	printf("  OS/ABI:               %s\n", get_osabi_name(elf.e_ident[7]));
	printf("  ABI Version:          %d\n", elf.e_ident[8]);
	printf("  Type:                 %s\n", get_file_type(elf.e_type));
	printf("  Machine:              %s\n", get_machine_name(elf.e_machine));
	printf("  Version:              0x%x\n", elf.e_version);
	printf("  Entry point address:              0x%x\n", elf.e_entry);
	printf("  Start of program headers:         %d (byte into file)\n", elf.e_phoff);
	printf("  Start of section headers:         %d (byte into file)\n", elf.e_shoff);
	printf("  Flags::                           0x%x\n", elf.e_flags);
	printf("  Size of this header:              %d (byte into file)\n", elf.e_ehsize);
	printf("  Size of program headers:          %d (byte into file)\n", elf.e_phentsize);
	printf("  Number of program headers:        %d \n", elf.e_phnum);
	printf("  Size of section headers:          %d (byte into file)\n", elf.e_shentsize);
	printf("  Number of section headers:        %d \n", elf.e_shnum);
	printf("  Section header string table index:        %d \n", elf.e_shstrndx);
	
}
//获取节区表符号表的索引和节区表的数目
static struct elf *
get_elf_section_strtable (char *filename)
{
	int fd;
	struct elf *elf;
	elf = (struct elf *)malloc(sizeof(struct elf));
	if ((fd = open("a.out", O_RDONLY, 0644)) == -1) {
		printf("error\n");
	}

	read(fd, elf, sizeof(struct elf));

	return elf;
}


//获取节区表
static void 
get_elf_section (struct elf *elf, char *filename)
{
	int fd;
	int i;
	int count = elf->e_shnum; 	//这个是elf文件中所有的节区个数，在elf文件中所有的节区都放在一个结构体数组中
	int str_table = elf->e_shstrndx; //这个是字符表的节区的索引
	struct elf_section *elf_sh;
	char buffer[sizeof(struct elf_section) * count];
	if ((fd = open("a.out", O_RDONLY, 0644)) == -1) {
		printf("error\n");
	}
	lseek(fd, elf->e_shoff, SEEK_CUR);
	
	read(fd, buffer, sizeof(struct elf_section) * count);

	elf_sh = (struct elf_section *)buffer;
	char str_buffer[elf_sh[str_table].sh_size];
	struct elf_section *sh_str_table = &elf_sh[str_table];
	lseek(fd, sh_str_table->sh_offset, SEEK_SET); //将文件指针移到字符表节区所在的位置

	read(fd, str_buffer, sizeof(str_buffer));

	const char *const sh_str_p = str_buffer;
	printf("[Nr] Name\t\tType\t\tAddr\tOff\tSize\tEs  Flg  Lk  Inf  Al\n");
	for (i = 0; i < count; ++i) {
		printf("[%d] %-16s\t\t%-8x\t\t%-8x\t%-2d\t%-2d\t%02d  %d  %d  %d  %d\n",i,
					((sh_str_p + elf_sh[i].sh_name) == '\0')? "NULL":sh_str_p + elf_sh[i].sh_name,
					elf_sh[i].sh_type,elf_sh[i].sh_addr, elf_sh[i].sh_offset,
					elf_sh[i].sh_size, elf_sh[i].sh_entsize, elf_sh[i].sh_flags,
					elf_sh[i].sh_link, elf_sh[i].sh_info, elf_sh[i].sh_addralign);
	}
	
	close(fd);
}

//读取程序头
static void 
get_program_header (char *filename, struct elf *elf) 
{
	int fd;
	int i;
	int program_start = elf->e_phoff;
	struct elf_header *program_header;
	char buffer[elf->e_phnum * sizeof(struct elf_header)];
	if ((fd = open(filename, O_RDONLY, 0644)) == -1) {
		printf("open the file error!\n");
		exit(1);
	}

	lseek(fd, program_start, SEEK_CUR);
	read(fd, buffer, sizeof(struct elf_header) * elf->e_phnum);
	
	program_header = (struct elf_header *)buffer;
	for (i = 0; i < elf->e_phnum; ++i) {
		printf("%x\t%x\t%x\t%x\n", program_header[i].p_offset, program_header[i].p_type, 
					program_header[i].p_vaddr,
				program_header[i].p_filesz);
	}

}
int main(int argc, char *argv[])
{
	struct elf *elf;
	get_elf_header("drock");
	elf = get_elf_section_strtable("drock");
	get_elf_section(elf, "drock");
	get_program_header("drock", elf);
	return EXIT_SUCCESS;
}

#if 0
int main(int argc, char *argv[])
{
	int fd;
	char buffer[12800];
	char str_buffer[1024];
	int number;
	struct elf *elf;
	struct elf_section *elf_sh;
	int i;

	if ((fd = open("a.out", O_RDONLY, 0644)) == -1) {
		printf("error\n");
	}

	number = read(fd, buffer, sizeof(struct elf));
	elf = (struct elf *)buffer;
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; ++i) {
		printf("%2.2x ", elf->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                %s\n", get_elf_class(elf->e_ident[4]));
	printf("  Date:                 %s\n", get_elf_data(elf->e_ident[5]));
	printf("  Version:              %d%s\n", elf->e_ident[6], "(current)");
	printf("  OS/ABI:               %s\n", get_osabi_name(elf->e_ident[7]));
	printf("  ABI Version:          %d\n", elf->e_ident[8]);
	printf("  Type:                 %s\n", get_file_type(elf->e_type));
	printf("  Machine:              %s\n", get_machine_name(elf->e_machine));
	printf("  Version:              0x%x\n", elf->e_version);
	printf("  Entry point address:              0x%x\n", elf->e_entry);
	printf("  Start of program headers:         %d (byte into file)\n", elf->e_phoff);
	printf("  Start of section headers:         %d (byte into file)\n", elf->e_shoff);
	printf("  Flags::                           0x%x\n", elf->e_flags);
	printf("  Size of this header:              %d (byte into file)\n", elf->e_ehsize);
	printf("  Size of program headers:          %d (byte into file)\n", elf->e_phentsize);
	printf("  Number of program headers:        %d \n", elf->e_phnum);
	printf("  Size of section headers:          %d (byte into file)\n", elf->e_shentsize);
	printf("  Number of section headers:        %d \n", elf->e_shnum);
	printf("  Section header string table index:        %d \n", elf->e_shstrndx);
	
	int count = elf->e_shnum; 	//这个是elf文件中所有的节区个数，在elf文件中所有的节区都放在一个结构体数组中
	int str_table = elf->e_shstrndx; //这个是字符表的节区的索引
	lseek(fd, elf->e_shoff - sizeof(struct elf), SEEK_CUR);
	
	number = read(fd, buffer, sizeof(struct elf_section) * count);
	elf_sh = (struct elf_section *)buffer;
	struct elf_section *sh_str_table = &elf_sh[str_table];
	lseek(fd, sh_str_table->sh_offset, SEEK_SET); //将文件指针移到字符表节区所在的位置

	number = read(fd, str_buffer, sizeof(str_buffer));

	const char *const sh_str_p = str_buffer;
	printf("[Nr] Name\t\tType\t\tAddr\tOff\tSize\tEs  Flg  Lk  Inf  Al\n");
	for (i = 0; i < count; ++i) {
		printf("[%d] %-16s\t\t%-16x\t\t%-08x\t%-06d\t%-06d\t%02d  %d  %d  %d  %d\n",i,
					((sh_str_p + elf_sh[i].sh_name) == '\0')? "NULL":sh_str_p + elf_sh[i].sh_name,
					elf_sh[i].sh_type,elf_sh[i].sh_addr, elf_sh[i].sh_offset,
					elf_sh[i].sh_size, elf_sh[i].sh_entsize, elf_sh[i].sh_flags,
					elf_sh[i].sh_link, elf_sh[i].sh_info, elf_sh[i].sh_addralign);
	}
	
	close(fd);
	return EXIT_SUCCESS;
}
#endif 
