
for i := 0; i < N; i++ { 
    create_os_thread(schedule) // 创建一个操作系统线程执行schedule函数
}

//schedule函数
func schedule() {
   for { 
         g := find_a_runnable_goroutine_from_M_goroutines()
         run_g(g) //运行当前goroutine
         save_status_of_g(g) //保存goroutine状态，主要是寄存器
    }
}