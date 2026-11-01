#ifndef OLLAMA_API_H
#define OLLAMA_API_H

#include <nlohmann/json.hpp>

#include <string>
#include <vector>

namespace ollama {

struct Message {
  std::string role{};
  std::string content{};
};

struct Post {
  std::string model{};
  std::vector<Message> message{};
  bool stream{false};
};

struct Response {
  std::string model{};
  std::string createdAt{};
  Message message{};
  bool done{false};
  std::string doneReason{};
};

inline void to_json(nlohmann::json &j, const Message &message) {
  j = nlohmann::json{{"role", message.role}, {"content", message.content}};
}

inline void from_json(const nlohmann::json &j, Message &message) {
  j.at("role").get_to(message.role);
  j.at("content").get_to(message.content);
}

inline void to_json(nlohmann::json &j, const Post &post) {
  j = nlohmann::json{{"model", post.model},
                     {"message", post.message},
                     {"stream", post.stream}};
}

inline void from_json(const nlohmann::json &j, Response &response) {
  j.at("model").get_to(response.model);
  j.at("created_at").get_to(response.createdAt);
  j.at("message").get_to(response.message);
  j.at("done").get_to(response.done);
  j.at("done_reason").get_to(response.doneReason);
}
}; // namespace ollama

#endif