# HugoBlog

Personal blog (static site) using Hugo. http://people.tamu.edu/~pdwarkanath/blog/

[Hugo](https://gohugo.io/) is a framework for building static sites. Written in [go](https://golang.org/), Hugo supports writing content in Markdown. To build your own Hugo site:

## Install Hugo

Check the [Hugo Releases page](https://github.com/gohugoio/hugo/releases) and download the compressed file for the latest release corresponding to your OS.

Extract the contents of the compressed file into a folder. Let's say you extract it in a folder named "Hugo". There will be 3 files in the folder:
1. hugo.exe
2. LICENSE
3. README.md

You will need to add the path to this folder to the ``Path`` environment variable for your system. For Windows 10, follow these [instructions to modify ``Path`` variable](https://gohugo.io/getting-started/installing/#for-windows-10-users).

```
hugo new site site-name
```

Replace site-name with the name that you want to use for your site. This will create a site in that folder. 

```
cd site-name
```

Use the above command to go to the site folder. Now you can start writing content for your site.

## Install a theme

Pick a theme from: https://themes.gohugo.io/

For this blog, I used [Minimal Bootstrap Hugo Theme](https://themes.gohugo.io/minimal-bootstrap-hugo-theme/). To install the theme, follow the instructions in the link to the theme.

Once the theme is installed, in the ``config.toml`` file for your site, add this line:

```
theme = "minimal-bootstrap-hugo-theme"
```

You can use the name of the theme you chose to install.

## Write content

When you are in the folder for your site,

```
hugo new posts/post-title.md
```

Replace post-title.md with the file name that you want to use for your post. You can now check the ``site-name/content/posts/`` folder to find the ``post-title.md`` file. Use any text editor of your choice to write your post in Markdown.

To preview your site before publishing, use:

```
hugo server -D
```

## Build Drafts


```
hugo -D
```

This command publishes all your drafts and converts them into html files in the 'public' folder.

## Publish

Finally to publish your site, copy your public folder to your hosting platform. For github pages, use the 'public' folder as a repository. In the repository settings, select the 'master' branch in the Github pages section and click save. Your site will be running on: http://username.github.io/repository 



My blog also uses Mathjax to support writing LaTeX syntax for mathematical expressions. Check the [Mathjax support for Hugo](https://gohugo.io/content-management/formats/#mathjax-with-hugo) to write mathematical expressions using LaTeX syntax in Markdown.

