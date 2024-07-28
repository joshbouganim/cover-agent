import os
import sys

# Add the parent directory to the sys.path
# sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from cover_agent.CoverAgent import CoverAgent

class Args:
    def __init__(self):
        self.source_file_path = "app.py"
        self.test_file_path = "test_app.py"
        self.test_file_output_path = ""
        self.code_coverage_report_path = "coverage.xml"
        self.test_command = f"coverage run --omit='test_app.py' --omit='test_recurse.py' --omit='/home/josh/dev/cover-agent/cover_agent/*' -m pytest && coverage report && coverage xml"
        self.test_command_dir = os.getcwd()
        self.included_files = None
        self.coverage_type = "cobertura"
        self.report_filepath = "test_results.html"
        self.desired_coverage = 70
        self.max_iterations = 3
        self.additional_instructions = ""
        self.model = "gpt-4o"
        self.api_base = "http://localhost:11434"
        self.prompt_only = False
        self.strict_coverage = False
        self.recurse = True

if __name__ == "__main__":
    # Keep track of total token count for cost monitoring
    total_input_token_count = 0
    total_output_token_count = 0

    args = Args()
    agent = CoverAgent(args)
    agent.run()

    total_input_token_count += agent.test_gen.total_input_token_count
    total_output_token_count += agent.test_gen.total_output_token_count

    print(f"Total input token count: {total_input_token_count}, total output token count: {total_output_token_count}")