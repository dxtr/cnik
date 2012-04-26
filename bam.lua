settings = NewSettings()
settings.cc.exe_c = "gcc"
settings.cc.flags_c:Add("-Wall", "-O0", "-g")
settings.cc.includes:Add("include")
settings.link.exe = "clang"

objs = Compile(settings, Collect("src/*.c"))
exe = Link(settings, "cnik", objs) 
