#! /bin/sh

set -x
echo "The program $0 is now running"
echo "The first parameter is $1"
echo "The second parameter is $2"
echo "The parameter list is $@"
shift
set +x
echo "The first parameter is $1"
echo "The second parameter is $2"
echo "The parameter list is $@"
