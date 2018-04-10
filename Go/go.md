Go����ѧϰ�ʼ�
========================

### ��ζ����άslice
```
g := make([][]int,5)
for i,_ := range g{
	g[i] = make([]int,5)
}

```
### ��ζ����ά����
```
go := [2][4]int{[4]int{1,2,3,4},[4]int{1,2,3,4}}

go := [2][4]int{{1,2,3,4},{1,2,3,4}}
```

### ��γ�ʼ���ṹ��
```
type User struct {
    Name   string
    Passwd string
}
func main() {
    user := &User{"chronos", "pass"}
}
```


### ��ȡstruct��tag
��ȡtag�����������÷������ʵ�ֵ�
```
package main
import (
    "fmt"
    "reflect" //��������reflectģ��
)
type User struct {
    Name   string "user name" //����������ľ���tag
    Passwd string "user passsword"
}
func main() {
    user := &User{"chronos", "pass"}
    s := reflect.TypeOf(user).Elem() //ͨ�������ȡtype����
    for i := 0; i < s.NumField(); i++ {
        fmt.Println(s.Field(i).Tag) //��tag�������
    }
}
```

### go�����еĲ�������
ע��go������û�����ô��Σ��������������Ͱ�����Ƭ���ֵ䡢ͨ���ȣ�������Ƭ������ܸı�ֵ�����ǲ������ֵ����������
```
package main
import (
  "fmt"
)
func main() {
  m1 := make([]string, 1)
  m1[0] = "test"
  fmt.Println("���� func1 ǰ m1 ֵ:", m1)
  func1(m1)
  fmt.Println("���� func1 �� m1 ֵ:", m1)
  fmt.Println("���� func1 ǰ m1 ֵ:", m1)
  func2(m1)
  fmt.Println("���� func1 �� m1 ֵ:", m1)
}
func func1 (a []string) {
  a[0] = "val1"
  fmt.Println("func1��:", a)
}
func func2 (a []string) {
  a = append(a, "val1")
  fmt.Println("func1��:", a, cap(a))
}
```
### go���Դ������
��Ҫע��go�����У�import���ǰ����ڵ�·������package���ǰ���

### go���Դ���json
```
//������֪json��
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

//����δ֪json��
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
	//fΪ�ӿ����ͣ�ͨ��ʹ�ö��Խ��д���json
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

//����json��
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
### go���Բ���
go������string,slice,map���������͵�ʵ�ֻ�������ָ�룬���Կ���ֱ�Ӵ��ݣ�������ȡ��ַ�󴫵�ָ�룬����Ҫע�⣬��������Ҫ�ı�slice�ĳ��ȣ�������Ҫȡ��ַ����ָ�롣

### go�������������ؽ������
���ڳ��Ƿ���ǽ�����⣬golang.org/xģ���������أ���˿������½������
```
git clone https://github.com/golang/net.git $GOPATH/src/github.com/golang/net
git clone https://github.com/golang/sys.git $GOPATH/src/github.com/golang/sys
git clone https://github.com/golang/tools.git $GOPATH/src/github.com/golang/tools
ln -s $GOPATH/src/github.com/golang $GOPATH/src/golang.org/x
```

### go����ѧϰ��¼

- ��Go��̻�����https://github.com/Unknwon/go-fundamental-programming
