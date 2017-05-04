.name		"Labels"
.comment	"Labels testing for the ASM"

start:	live %1
	and r1,%0,r1
end:	zjmp %:start
