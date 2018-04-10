Go语言学习笔记
========================

### 如何定义二维slice
```
g := make([][]int,5)
for i,_ := range g{
	g[i] = make([]int,5)
}

```
### 如何定义二维数组
```
go := [2][4]int{[4]int{1,2,3,4},[4]int{1,2,3,4}}

go := [2][4]int{{1,2,3,4},{1,2,3,4}}
```

### 如何初始化结构体
```
type User struct {
    Name   string
    Passwd string
}
func main() {
    user := &User{"chronos", "pass"}
}
```


### 获取struct的tag
获取tag的内容是利用反射包来实现的
```
package main
import (
    "fmt"
    "reflect" //这里引入reflect模块
)
type User struct {
    Name   string "user name" //这引号里面的就是tag
    Passwd string "user passsword"
}
func main() {
    user := &User{"chronos", "pass"}
    s := reflect.TypeOf(user).Elem() //通过反射获取type定义
    for i := 0; i < s.NumField(); i++ {
        fmt.Println(s.Field(i).Tag) //将tag输出出来
    }
}
```

### go语言中的参数传递
注意go语言中没有引用传参，但存在引用类型包含切片、字典、通道等，其中切片传入后能改变值，但是不能添加值，具体如下
```
package main
import (
  "fmt"
)
func main() {
  m1 := make([]string, 1)
  m1[0] = "test"
  fmt.Println("调用 func1 前 m1 值:", m1)
  func1(m1)
  fmt.Println("调用 func1 后 m1 值:", m1)
  fmt.Println("调用 func1 前 m1 值:", m1)
  func2(m1)
  fmt.Println("调用 func1 后 m1 值:", m1)
}
func func1 (a []string) {
  a[0] = "val1"
  fmt.Println("func1中:", a)
}
func func2 (a []string) {
  a = append(a, "val1")
  fmt.Println("func1中:", a, cap(a))
}
```
### go语言打包问题
需要注意go语言中，import的是包所在的路径，而package的是包名

### go语言处理json
```
//解析已知json包
package main
import (
	"encoding/json"
	"fmt"
)
type Server struct{
	ServerName string
	ServerIP string
}
type Serverslice struct{
	Servers []Server
}
func main(){
	var s Serverslice
	str := `{"servers":[{"serverName":"Shanghai_VPN","serverIP":"127.0.0.1"} ,{"serverName":"Beijing_VPN","serverIP":"127.0.0.2"}]}`
	json.Unmarshal([]byte(str),&s)
	fmt.Println(s)
}

//解析未知json包
package main
import (
	"encoding/json"
	"fmt"
)
func main(){
	b := []byte(`{"Name":"Wednesday","Age":6,"Parents":["Gomez","Morticia"]}`)
	var f interface{}
	err := json.Unmarshal(b,&f)
	if err != nil{
		fmt.Println("error")
	}
	//f为接口类型，通过使用断言进行处理json
	m := f.(map[string]interface{})
	for k,v := range m{
		switch vv := v.(type){
		case string:
			fmt.Println(k,"is string",vv)
		case int:
			fmt.Println(k,"is int",vv)
		case float64:
			fmt.Println(k,"is float64",vv)
		case []interface{}:
			fmt.Println(k,"is an array:")
			for i,u := range vv{
				fmt.Println(i,u)
			}
		default:
			fmt.Println(k,"is of a type I don't know how to handle")
		}
	}
}

//构建json包
package main

import (
	"encoding/json"
	"fmt"
)

type Server struct{
	ServerName string
	ServerIP string
}

type Serverslice struct{
	Servers []Server
}

func main(){
	var s Serverslice
	s.Servers = append(s.Servers,Server{ServerName:"Shanghai_VPN",ServerIP:"127.0.0.1"})
	s.Servers = append(s.Servers,Server{ServerName:"Beijing_VPN",ServerIP:"127.0.0.2"})
	b,err := json.Marshal(s)
	if err != nil{
		fmt.Println("json err",err)
	}
	fmt.Println(string(b))
}
```
### go语言参数
go语言中string,slice,map这三种类型的实现机制类似指针，所以可以直接传递，而不用取地址后传递指针，但需要注意，若函数需要改变slice的长度，则仍需要取地址传递指针。

### go第三方库难下载解决方案
由于长城防火墙的问题，golang.org/x模块难以下载，因此可以如下解决方案
```
git clone https://github.com/golang/net.git $GOPATH/src/github.com/golang/net
git clone https://github.com/golang/sys.git $GOPATH/src/github.com/golang/sys
git clone https://github.com/golang/tools.git $GOPATH/src/github.com/golang/tools
ln -s $GOPATH/src/github.com/golang $GOPATH/src/golang.org/x
```

### go重新学习记录

- 《Go编程基础》https://github.com/Unknwon/go-fundamental-programming
