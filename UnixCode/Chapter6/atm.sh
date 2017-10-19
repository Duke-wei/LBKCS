#########################################################################
# File Name: atm.sh
# Author: Duke-wei
# mail: 13540639584@163.com
# Created Time: 2017年10月10日 星期二 12时43分36秒
#########################################################################
#!/bin/bash
while true
do
	./do_a_transaction
	if ./play_again
	then
		continue
	fi
	break
done
