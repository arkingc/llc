package main

import (
	"fmt"
	"github.com/spf13/cobra"
	"path"
	"sync"
)

var (
	useNaiveDiffLock sync.Once
)

type Man interface {
	speak()
}

type Student interface {
	study()
}

type BoyStudent struct {
}

func (bs *BoyStudent) speak() {
	fmt.Println("I'm a man, I can speak!")
}

func (bs *BoyStudent) study() {
	fmt.Println("I'm a student,I can study!")
}

func (bs *BoyStudent) String() string {
	return "FUCK HAHA"
}

func unseNaiveDiff() {
	useNaiveDiffLock.Do(func() {
		fmt.Println("Do func!")
	})
}

func main() {
	unseNaiveDiff()
	unseNaiveDiff()
	unseNaiveDiff()
	unseNaiveDiff()
	bs := &BoyStudent{}

	bs.speak()
	bs.study()

	fmt.Println(bs)

	fmt.Println(path.Join("path join test:", "hello world"))
	//1.定义主命令
	var Version bool
	var rootCmd = &cobra.Command{
		Use:   "root [sub]",
		Short: "My root command",
		//命令执行的函数
		Run: func(cmd *cobra.Command, args []string) {
			fmt.Printf("Inside rootCmd Run with args: %v\n", args)
			if Version {
				fmt.Printf("Version:1.0\n")
			}
		},
	}
	//2.定义子命令
	var subCmd = &cobra.Command{
		Use:   "sub [no optionzs!]",
		Short: "My subcommand",
		//命令执行的函数
		Run: func(cmd *cobra.Command, args []string) {
			fmt.Printf("Inside subCmd Run with args: %v\n", args)
		},
	}
	//添加子命令
	rootCmd.AddCommand(subCmd)
	//3.为命令添加选项
	flags := rootCmd.Flags()
	flags.BoolVarP(&Version, "version", "v", false, "Print version information and quit")
	//执行命令
	_ = rootCmd.Execute()
}
