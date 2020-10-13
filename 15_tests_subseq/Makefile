all:maxSeq test-subseq

maxSeq:maxSeq.c
	gcc -c maxSeq.c
test-subseq:test-subseq.c maxSeq.c
	gcc -o test-subseq test-subseq.c maxSeq.c
