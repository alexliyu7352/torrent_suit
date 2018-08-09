FROM centos

MAINTAINER phantom9999

RUN yum -y install epel-release.noarch

RUN yum -y install boost-devel.x86_64 libevent-devel.x86_64 gflags-devel.x86_64 glog-devel.x86_64 thrift-devel.x86_64 hiredis-devel.x86_64 protobuf-devel.x86_64 snappy-devel.x86_64 log4cpp-devel.x86_64 java-1.8.0-openjdk-devel.x86_64 cmake3 gcc-c++ openssl-devel.x86_64 gtest-devel.x86_64

ADD . /root/torrent
RUN cd /root/torrent/; sh proto_gen.sh ;cmake3 . ; make -j4


