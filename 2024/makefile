HELPER:=./.helper
HELPER_DEP:=$(HELPER)/libaoc.a $(HELPER)/aoc.h
HELPER_INC:=-L$(HELPER) -I$(HELPER)

a%: day%/a.c $(HELPER_DEP)
	gcc -g3 $(HELPER_INC) day$*/a.c -o day$*/a -laoc

b%: day%/b.c $(HELPER_DEP)
	gcc -g3 $(HELPER_INC) day$*/b.c -o day$*/b -laoc