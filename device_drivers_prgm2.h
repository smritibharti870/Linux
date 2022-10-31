#include<linux/module.h>
#include<linux/kernal.h>
#include<linux/init.h>

static int __init tata_elxsi_start (void)
{
printk(KERN_INFO "Hello, world 2\n");
return 0;
}
static void __exit tata_elxsi_end(void)
{
printk(KERN_INFO "Goodbye, world 2\n");
}
module_init(tata_elxsi_start);
module_exit(tata_elxsi_end);

