" Vim with all enhancements
source $VIMRUNTIME/vimrc_example.vim
filetype detect
set hls
set is
set si

set nocompatible
set exrc
set mouse=a
set tabstop=4
set shiftwidth=4

set smarttab
set autoindent
set smartindent
set cindent
set showcmd
set number
set autowrite
set autoread

set nowrap

set cmdheight=2
map <F1> :<C-U>!g++ -O2 -DLOCAL -std=c++14 -Wall -Wextra -Wno-unused-result -static %:r.cpp -o %:r<CR>
map <F2> :<C-U>!%:r<CR>

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

set nu
augroup numbertoggle
	autocmd!
	autocmd BufEnter,FocusGained,InsertLeave * set rnu
	autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
	if &sh =~ '\<cmd'
	  if empty(&shellxquote)
		let l:shxq_sav = ''
		set shellxquote&
	  endif
	  let cmd = '"' . $VIMRUNTIME . '\diff"'
	else
	  let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
	endif
  else
	let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
	let &shellxquote=l:shxq_sav
  endif
endfunction

call plug#begin()
	Plug 'scrooloose/nerdtree'
	Plug 'flazz/vim-colorschemes'
	Plug 'preservim/nerdcommenter'
call plug#end()

map <C-n> :NERDTree
