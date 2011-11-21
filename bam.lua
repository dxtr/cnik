settings = NewSettings()
settings.cc.exe_c = "clang"
settings.cc.flags_c:Add("-Wall", "-std=c99", "-O0", "-g")
settings.cc.includes:Add("./src/")
settings.link.exe = "clang"

objs = Compile(settings, Collect("src/*.c", "src/list/*.c", "src/bst/*.c"))
exe = Link(settings, "cnik", objs) 
