#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched/signal.h>

MODULE_AUTHOR("Aman Nehra");
MODULE_DESCRIPTION("LKM : Listing all the processes");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static int __init list_processes_lkm_init(void){
    struct task_struct *task;
    for_each_process(task){
        printk(KERN_INFO "PID:%d\t\tState:%ld\t\tName:%s\n",task->pid,task->state,task->comm);
    }
    return 0;
}

static void __exit list_processes_lkm_exit(void){
    printk(KERN_INFO "Listed all the processes\n");
}

module_init(list_processes_lkm_init);
module_exit(list_processes_lkm_exit);