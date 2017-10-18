/*~-------------------------------------------------------------------------~~*
 * Copyright (c) 2014 Los Alamos National Security, LLC
 * All rights reserved.
 *~-------------------------------------------------------------------------~~*/

///
/// \file
/// \date Initial file creation: Oct 17, 2017
///


#include <cinchtest.h>

#include "flecsi/execution/execution.h"
#include "flecsi/io/simple_definition.h"
#include "flecsi/coloring/dcrs_utils.h"
#include "flecsi/supplemental/coloring/add_colorings.h"
#include "flecsi/supplemental/mesh/empty_mesh_2d.h"
#include "flecsi/data/legion/future_policy.h"
#include "flecsi/data/future_handle.h" 

using namespace flecsi;
using namespace supplemental;

clog_register_tag(coloring);


template<typename T>
using future_handle_t = future_handle_t<T>;

#if 0
void task1(future_handle_t<double> x, double y) {
  //np(y);
} // task1

void future_handle_dump(future_handle_t<double> x) {
  clog(info) << "future_handle =  " << x << std::endl;
}

void writer(future_handle_t<double> x) {
  clog(info) << "writer write" << std::endl;
  x = 3.14;
}

void reader(future_handle_t<double> x) {
  clog(info) << "reader read: " << std::endl;
  ASSERT_EQ(x, static_cast<double>(3.14));
  
}

flecsi_register_task(task1, loc, single);
flecsi_register_task(future_handle_dump, loc, single);
flecsi_register_task(writer, loc, single);
flecsi_register_task(reader, loc, single);
#endif

flecsi_register_future( ns, pressure, double, 0);

namespace flecsi {
namespace execution {

//----------------------------------------------------------------------------//
// Specialization driver.
//----------------------------------------------------------------------------//

void specialization_tlt_init(int argc, char ** argv) {
  clog(info) << "In specialization top-level-task init" << std::endl;

  auto & context = execution::context_t::instance();
 
  ASSERT_EQ(context.execution_state(),
    static_cast<size_t>(SPECIALIZATION_TLT_INIT));

//  auto future = flecsi_get_future(ns, pressure, double, 0);
#if 0
  flecsi_execute_task(global_data_handle_dump, single, future);
  flecsi_execute_task(global_writer, single, future);
  flecsi_execute_task(global_reader, single, future);
#endif
} // specialization_tlt_init

//----------------------------------------------------------------------------//
// User driver.
//----------------------------------------------------------------------------//

void driver(int argc, char ** argv) {
  clog(info) << "In driver" << std::endl;

  auto & context = execution::context_t::instance();
  ASSERT_EQ(context.execution_state(), static_cast<size_t>(DRIVER));

  int rank, size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);


//   auto future = flecsi_get_future(ns, pressure, double, 0);
#if 0
//  flecsi_execute_task(task1, single, h, 128);
  flecsi_execute_task(data_handle_dump, single, future);
  flecsi_execute_task(exclusive_writer, single, future);
  flecsi_execute_task(exclusive_reader, single, future);
#endif

} // driver

//----------------------------------------------------------------------------//
// TEST.
//----------------------------------------------------------------------------//

TEST(data_handle, testname) {
  
} // TEST

} // namespace execution
} // namespace flecsi

/*~------------------------------------------------------------------------~--*
 * Formatting options for vim.
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~------------------------------------------------------------------------~--*/

#undef DH2
