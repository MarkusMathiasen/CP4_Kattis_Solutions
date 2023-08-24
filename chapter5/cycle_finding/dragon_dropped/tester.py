#!/usr/bin/env python3
#
# Testing tool for the Going in Circles problem
#
# Usage:
#
#   python3 testing_tool.py [-s sequence] <program>
#
# The sequence must consist of characters '0' and '1' and have length at least 3.
# If no initial sequence is specified, the sample (011) is used.
#
# You can compile and run your solution as follows.
# - You may have to replace 'python3' by just 'python'.
# - On Windows, you may have to replace '/' by '\'.
#
# If you have a C++ solution stored in a file called "sol.cpp",
# you must first compile using "g++ sol.cpp -o sol" and then
# invoke the testing tool with:
#
#   python3 testing_tool.py ./sol

import argparse
import subprocess
import sys
import traceback


def write(p, line):
	assert p.poll() is None, 'Program terminated early'
	print('Write: {}'.format(line), flush=True)
	p.stdin.write('{}\n'.format(line))
	p.stdin.flush()


def read(p):
	assert p.poll() is None, 'Program terminated early'
	line = p.stdout.readline().strip()
	assert line != '', 'Read empty line or closed output pipe. Make sure that your program started successfully.'
	print('Read: %s' % line, flush=True)
	return line


def wrong_answer(p, reason):
	sys.stdout.write('%s\n' % reason)
	p.kill()


parser = argparse.ArgumentParser(description='Testing tool for the Dragon Dropped problem')
parser.add_argument('-mu', dest='mu', metavar='mu', default="1")
parser.add_argument('-lam', dest='lam', metavar='lam', default="2")
parser.add_argument('-n', dest='n', metavar='n', default="4")
parser.add_argument('program', nargs='+', help='Invocation of your solution')

args = parser.parse_args()

mu = int(args.mu)
lam = int(args.lam)
n = int(args.n)

pos = [0, 0]
goal = ((n-mu)%lam)+mu if n > mu else n

queries = 0
queries_acc = 30000
queries_limit = 1000000

def invalid_response(p, r):
	wrong_answer(p, 'Program gave invalid response: ' + r)

def real_pos(p):
	global lam
	global mu
	if p < mu: return p
	return ((p-mu)%lam)+mu

with subprocess.Popen(" ".join(args.program), shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE, universal_newlines=True) as p:
	try:
		write(p, n)

		while True:
			if queries > queries_limit:
				wrong_answer(p, 'Program used too many queries, aborting')
				break
			queries += 1

			response = read(p)
			A = response.split()
			if len(A) != 2:
				invalid_response(p, response)
			action, person = A[0], A[1]
			if not action in ["NEXT", "RETURN", "ASK"]:
				invalid_response(p, response)
			if not person in ["GABBY", "SPIKE"]:
				invalid_response(p, response)
			pers = int(person == "GABBY")

			if action == "NEXT":
				s = pos[pers] != n
				if s: pos[pers] += 1
				write(p, str(int(s)) + " " + str(int(real_pos(pos[0]) == real_pos(pos[1]))))

			elif action == "RETURN":
				pos[pers] = 0
				write(p, "1 " + str(int(real_pos(pos[0]) == real_pos(pos[1]))))
			elif action == "ASK":
				res = real_pos(n) == real_pos(pos[pers])
				if res:
					assert queries <= queries_acc, 'Program printed correct solution, but used too many queries'
					assert p.stdout.readline() == '', 'Printed extra data after finding solution'
					assert p.wait() == 0, 'Did not exit cleanly after finishing'
					break
				else:
					wrong_answer(p, 'Program printed incorrect solution')
					break
	except:
		traceback.print_exc()
	finally:
		sys.stdout.flush()
		sys.stderr.flush()
		sys.stdout.write(f'Used {queries} queries, limit is {queries_acc}.\nProgram exit code: {p.wait()}\n')
		sys.stdout.flush()
