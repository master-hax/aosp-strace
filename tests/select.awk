BEGIN {
	r[1] = "^p?select6?\\(2, \\[0 1\\], \\[0 1\\], \\[0 1\\], NULL(, 0)?\\) += 1 \\(\\)$"
	r[2] = "^p?select6?\\(-1, NULL, 0x[0-9a-f]+, NULL, NULL(, 0)?\\) += -1 "
	r[3] = "^p?select6?\\(1025, \\[0\\], \\[\\], NULL, \\{0, 100(000)?\\}(, 0)?\\) += 0 \\(Timeout\\)$"
	r[4] = "^\\+\\+\\+ exited with 0 \\+\\+\\+$"
	lines = 4
	fail = 0
}

NR > lines { exit 1 }

{
	if (match($0, r[NR]))
		next

	print "Line " NR " does not match."
	fail = 1
}

END {
	if (fail == 0 && NR != lines) {
		fail = 1
		print "Expected " lines " lines, found " NR " line(s)."
	}
	exit fail
}
