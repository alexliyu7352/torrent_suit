#ifndef BBTS_AGENT_OPTIONS_PARSE_H
#define BBTS_AGENT_OPTIONS_PARSE_H

#include <string>

#include "pb_config/configure.pb.h"
#include "pb_config/message.pb.h"

namespace libtorrent {
struct ip_filter;
struct cluster_config_entry;
}

namespace bbts {

std::string get_cmd_string(int argc, char* argv[]);

message::SourceURI convert(const libtorrent::cluster_config_entry &cluster_config);

std::string to_string(const message::SourceURI &source_uri);

bool parse_uri_entry(const std::string &uri, message::SourceURI *source_uri);

bool parse_ip_filter(const std::string &filter_string, int flags, libtorrent::ip_filter *filter);

bool parse_subnet_mask(const std::string &ip,
        const std::string &mask, libtorrent::ip_filter *filter);

std::pair<int, int> parse_port_range(const std::string &port_range);

void parse_tracker(const std::string &str, message::Server *tracker);

void parse_attributes(const std::string &attr_str);

void print_task_status_header();

void print_task_status(const message::TaskStatus &task_status);

void print_status(const message::Status &status, bool debug);

bool check_cluster_uri(const std::string &uri);

bool check_download_configure(const message::DownloadConfigure &configure);

} // namespace bbts

#endif // BBTS_AGENT_OPTIONS_PARSE_H
