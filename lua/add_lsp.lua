local M = {}

M.setup = function(opts)
	local configs = require "lspconfig/configs"
	local util = require "lspconfig/util"
	local lspconfig = require "lspconfig"

	if not opts then
		opts = {}
	end

	assert(not lspconfig.matlab, "Server already exists")
	configs.matlab = {
		default_config = {
			filetypes = { "matlab" },
			root_dir = function(fname)
				return util.path.dirname(fname)
			end,
			cmd = { "matlab_lsp" },
			settings = {},
		},
		docs = {
			description = [[
      Test description
    ]],
			default_config = {
				root_dir = [[dirname]],
			},
		},
	}

	lspconfig.matlab.setup(opts)
end

return M
