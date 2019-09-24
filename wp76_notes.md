
# leaf
```
leaf setup <profile name> -p <package identifier>
```

Current package identifiers
```
swi-wp76_4.0.2 
swi-wp85_3.0.0 
```

Basically install the build system - takes a long time
```
leaf setup currentWp76 -p swi-wp76_4.0.2

leaf setup currentWP85 -p swi-wp85_3.0.0

```

Select the module profile to use
```
leaf select currentWp76
```

Check this with 
```
leaf status
```

Run a shell which is configure to build legato stuff
```
leaf shell
Leaf Shell /bin/bash started in Leaf environment.

(lsh:currentWp76) john@john-VirtualBox-ST:~/WP76$
```

Build the legato system
```
mksys -t wp76xx mySys.sdef
```

Build an individual app - disadvantage is that the interfaces are not fully checked
```
mkapp -s components -t wp76xx -i ./leaf-data/current/wp76-legato/interfaces/modemServices ./apps/wan/wan.adef
```

# Visual Studio Code


[Sierra install info](https://docs.legato.io/latest/tools_vsCode.html)

[Microsoft install info](https://code.visualstudio.com/Download)

[Microsoft Getting Started](https://code.visualstudio.com/docs/?dv=linux64_deb)


## Build

CTRL SHIFT B

# Target
Command line - has utilities from busybox 

Process list
```
ps -A
```

```
top
```




