#include <linux/module.h>

static int __init simple_init(void)
{
	pr_info("Namaste %s ..\n", module_name(THIS_MODULE));
	return 0;
}

static void __exit simple_exit(void)
{
	pr_info("Shubham %s ...\n", module_name(THIS_MODULE));
}

module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
