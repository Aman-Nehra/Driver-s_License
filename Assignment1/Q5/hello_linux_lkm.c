#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

MODULE_AUTHOR("Aman Nehra");
MODULE_DESCRIPTION("LKM : First LKM Code");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static int __init hello_linux_lkm_init(void){
    printk(KERN_INFO "Hello linux, my love >3\n");
    return 0;
}

static void __exit hello_linux_lkm_exit(void){
    printk(KERN_INFO "Goodbye linux, my love >3\n");
}

module_init(hello_linux_lkm_init);
module_exit(hello_linux_lkm_exit);