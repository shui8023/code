/*编译的方法：
 *gcc -c ld.c -o ld.o -fno-builtin -m32
 *ld -T ld.lds ld.o -o ld -m elf_i386 -static
 *./ld
 */


char *str = "hello word!\n";

void print()
{
	asm ("movl $13, %%edx   \n\t"
		"movl %0, %%ecx \n\t"
		"movl $0, %%ebx \n\t"
		"movl $4, %%eax \n\t"
		"int $0x80 	 \n\t"
		::"r"(str):"edx", "ecx", "ebx");
}
/*这里的汇编实际上实现了write函数，系统调用：系统调用通过0x80中断实现，其中eax为调用号，ebx，ecx，edx等通用寄存器用来传递参数，
*int write (int filedesc, char *buffer, int size )
*write 调用的调用号为4,则eax = 0;
*filedesc表示被写入文件句柄，使用ebx寄存器传递，我们是向输出设备输出，它的句柄为0，则ebx=0;
*buffer 表示要写入的缓冲区地址，使用ecx寄存器传递，我们这里要输出的字符串str，所以ecx = str
*size表示要写入的字节数，使用edx寄存器传递，
*/
void exit()
{
	asm("movl $42, %ebx \n\t"
		"movl $1, %eax \n\t"
		"int $0x80 	\n\t");
}
/*exit()系统调用中，ebx表示进程推出码（exit CODE）以42为进程退出玛退出的。
 *
 *
 *
 */
void nomain()
{
	print();
	exit();
}
