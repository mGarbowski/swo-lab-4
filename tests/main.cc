#define APPROVALS_CATCH2_V3
#include "ApprovalTests.hpp"

auto directoryDisposer =
    ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests");
auto defaultReporterDisposer = ApprovalTests::Approvals::useAsDefaultReporter(
    std::make_shared<ApprovalTests::CrossPlatform::VisualStudioCodeReporter>());
