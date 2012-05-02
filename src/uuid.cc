// Copyright (C) 2010 Nikhil Marathe <nsm.nikhil@gmail.com>

#include <cstring>

#include <v8.h>
#include <node.h>

#include <uuid/uuid.h>

using namespace v8;
using namespace node;

namespace uuid_v8 {

Handle<Value> Generate( const Arguments &args ) {
  HandleScope scope;

  uuid_t new_uuid;
  uuid_generate( new_uuid );

  char str[40];
  uuid_unparse( new_uuid, str );

  return String::New( str, strlen( str ) );
}

}

extern "C"
void init( Handle<Object> target ) {
  HandleScope scope;
  Local<FunctionTemplate> t = FunctionTemplate::New(uuid_v8::Generate);

  target->Set( String::NewSymbol( "generate" ), t->GetFunction() );
}

