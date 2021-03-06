// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: testTask.proto
#ifndef GRPC_testTask_2eproto__INCLUDED
#define GRPC_testTask_2eproto__INCLUDED

#include "testTask.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace handler {

class MassiveHandlerService final {
 public:
  static constexpr char const* service_full_name() {
    return "handler.MassiveHandlerService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Handle(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::handler::Number* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::handler::Number>> AsyncHandle(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::handler::Number>>(AsyncHandleRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::handler::Number>> PrepareAsyncHandle(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::handler::Number>>(PrepareAsyncHandleRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Handle(::grpc::ClientContext* context, const ::handler::NumberMassive* request, ::handler::Number* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Handle(::grpc::ClientContext* context, const ::handler::NumberMassive* request, ::handler::Number* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Handle(::grpc::ClientContext* context, const ::handler::NumberMassive* request, ::handler::Number* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::handler::Number>* AsyncHandleRaw(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::handler::Number>* PrepareAsyncHandleRaw(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Handle(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::handler::Number* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::handler::Number>> AsyncHandle(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::handler::Number>>(AsyncHandleRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::handler::Number>> PrepareAsyncHandle(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::handler::Number>>(PrepareAsyncHandleRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Handle(::grpc::ClientContext* context, const ::handler::NumberMassive* request, ::handler::Number* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Handle(::grpc::ClientContext* context, const ::handler::NumberMassive* request, ::handler::Number* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Handle(::grpc::ClientContext* context, const ::handler::NumberMassive* request, ::handler::Number* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::handler::Number>* AsyncHandleRaw(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::handler::Number>* PrepareAsyncHandleRaw(::grpc::ClientContext* context, const ::handler::NumberMassive& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Handle_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Handle(::grpc::ServerContext* context, const ::handler::NumberMassive* request, ::handler::Number* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Handle : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Handle() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Handle() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Handle(::grpc::ServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestHandle(::grpc::ServerContext* context, ::handler::NumberMassive* request, ::grpc::ServerAsyncResponseWriter< ::handler::Number>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Handle<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Handle : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Handle() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::handler::NumberMassive, ::handler::Number>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::handler::NumberMassive* request, ::handler::Number* response) { return this->Handle(context, request, response); }));}
    void SetMessageAllocatorFor_Handle(
        ::grpc::experimental::MessageAllocator< ::handler::NumberMassive, ::handler::Number>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::handler::NumberMassive, ::handler::Number>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_Handle() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Handle(::grpc::ServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Handle(
      ::grpc::CallbackServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Handle(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_Handle<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_Handle<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Handle : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Handle() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Handle() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Handle(::grpc::ServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Handle : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Handle() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Handle() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Handle(::grpc::ServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestHandle(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Handle : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Handle() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Handle(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_Handle() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Handle(::grpc::ServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Handle(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Handle(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Handle : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Handle() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::handler::NumberMassive, ::handler::Number>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::handler::NumberMassive, ::handler::Number>* streamer) {
                       return this->StreamedHandle(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Handle() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Handle(::grpc::ServerContext* /*context*/, const ::handler::NumberMassive* /*request*/, ::handler::Number* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedHandle(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::handler::NumberMassive,::handler::Number>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Handle<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Handle<Service > StreamedService;
};

}  // namespace handler


#endif  // GRPC_testTask_2eproto__INCLUDED
