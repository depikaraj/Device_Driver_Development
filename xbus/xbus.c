/* Example - Creating a new bus */
#include <linux/module.h>
#include <linux/device.h> /* device model defs */
#include <linux/string.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("xbus example");

static int xbus_match(struct device *dev, struct device_driver *drv)
{
	pr_info("xbus match dev %s drv %s\n", dev_name(dev), drv->name);
	return sysfs_streq(dev_name(dev), drv->name);
}

struct bus_type xbus = {
	.name = "xbus",
	.match = xbus_match,
};

static int __init xbus_init(void)
{
	pr_info("xbus inited\n");
	bus_register(&xbus);
	return 0;
}
module_init(xbus_init);

static void __exit xbus_exit(void)
{
	pr_info("xbus exiting..");
	bus_unregister(&xbus);
}
module_exit(xbus_exit);
