ENTRY(nomain)
SECTIONS
{
	. = 0x08048000 + SIZEOF_HEADERS;
	/*0x08048000通常ELF可执行文件的起始地址虚拟地址是找个
	  */
	tinytext : { *(.text)*(.data)*(.rodata)
		   	. = ALIGN(4096);
			/* 把该section的VMA设置为定位符号的修调值，满足4KB对齐后的*/
		   }
	/DISCARD/ : {*(.commment)}
}

