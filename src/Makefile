ifneq ($(KERNELRELEASE),)
obj-m :=speaker.o
else
KSRC :=/lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)
default:
	$(MAKE) -C $(KSRC) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KSRC) SUBDIRS=$(PWD) clean
endif
