#########################################################################
# File Name: script2.sh
# Author: Duke-wei
# mail: 13540639584@163.com
# Created Time: 2017年10月14日 星期六 09时34分44秒
#########################################################################
#!/bin/bash
BOOk=$HOME/workspace/UnixCode/Cheapter9/x.data
echo find what name in phonebook
read NAME
if grep $NAME $BOOk>/tmp/pb.tmp
then
	echo Entries for $NAME
	cat /tmp/pb.tmp
else
	echo No entries for $NAME
fi
rm /tmp/pb.tmp
